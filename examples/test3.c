/*! gcc -std=c89 -pedantic -Wall -g -o test2 test2.c libkdtree.a -lm */
/* Extended test program, contributed by David Underhill */
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "kdtree.h"

#define DEF_NUM_PTS 1000000

/* returns the distance squared between two dims-dimensional double arrays */
static double dist_sq( double *a1, double *a2, int dims );

/* get a random double between -10 and 10 */
static double rd( void );

/* generate an array of random values for dimensions */
static void generate_dims(int num, double *nums);

int main(int argc, char **argv) {
  int i, num_pts = DEF_NUM_PTS;
  void *ptree;
  char *data, *pch;
  struct kdres *presults;
  double pos[50], dist;
  double pt[50];
  double nums[50];
  double radius = 40;

  for (i=0; i<50; ++i) {
    pt[i] = rd();
  }

  if(!(data = malloc(num_pts))) {
    perror("malloc failed");
    return 1;
  }

  srand( time(0) );
  
  /* create a k-d tree for 50-dimensional points */
  ptree = kd_create(50);
  
  /* add some random nodes to the tree (assert nodes are successfully inserted) */
  printf("Seeding %d entries of %d dimensions...\n", num_pts, 50);
  for( i=0; i<num_pts; ++i ) {
    data[i] = 'a' + i;
    generate_dims(50, nums);
    assert( 0 == kd_insert( ptree, nums, &data[i] ) );
  }

  /* find points closest to the origin and within distance radius */
  printf("Searching in radius of %1.02f...\n", radius);
  presults = kd_nearest_range( ptree, pt, radius );

  /* print out all the points found in results */
  printf( "found %d results:\n", kd_res_size(presults) );

  while( !kd_res_end( presults ) ) {
    /* get the data and position of the current result item */
    pch = (char*)kd_res_item( presults, pos );
    
    /* compute the distance of the current result from the pt */
    dist = sqrt( dist_sq( pt, pos, 50 ) );

    /* print out the retrieved data */
    //printf( "node at (%.3f, %.3f, %.3f) is %.3f away and has data=%c\n", 
	//    pos[0], pos[1], pos[2], dist, *pch );

    /* go to the next entry */
    kd_res_next( presults );
  }

  /* free our tree, results set, and other allocated memory */
  free( data );
  kd_res_free( presults );
  kd_free( ptree );

  return 0;
}

static double dist_sq( double *a1, double *a2, int dims ) {
  double dist_sq = 0, diff;
  while( --dims >= 0 ) {
    diff = (a1[dims] - a2[dims]);
    dist_sq += diff*diff;
  }
  return dist_sq;
}

static double rd( void ) {
  return (double)rand()/RAND_MAX * 20.0 - 10.0;
}

static void generate_dims(int num, double *nums)
{
  int i = 0;
  for (i=0; i<50; ++i) {
    nums[i] = rd();
  }
}
