#include <stdio.h>
#include "cv.h"
#include "highgui.h"
 
int main( int argc, char** argv )
{
  /* data structure for the image */
  IplImage *img = 0;
  int width, height;
  /* check for supplied argument */
  if( argc < 2 ) {
    fprintf( stderr, "Usage: loadimg <filename>\n" );
    return 1;
  }
   
  /* load the image,
     use CV_LOAD_IMAGE_GRAYSCALE to load the image in grayscale */
  img = cvLoadImage( argv[1], CV_LOAD_IMAGE_COLOR );
   
  /* always check */
  if( img == 0 ) {
    fprintf( stderr, "Cannot load file %s!\n", argv[1] );
    return 1;
  }
   
  /* print some properties */
  printf( "Filename:    %s\n",        argv[1] );
  printf( "# channels:  %d\n",        img->nChannels );
  printf( "Pixel depth: %d bits\n",   img->depth );
  printf( "width:       %d pixels\n", img->width );
  printf( "height:      %d pixels\n", img->height );
  printf( "Image size:  %d bytes\n",  img->imageSize );
  printf( "Width step:  %d bytes\n",  img->widthStep );

  width  = img->width;
  height = img->height;
 
  /* create new image for the grayscale version */
  IplImage *dst = cvCreateImage( cvSize( width, height ), IPL_DEPTH_8U, 1 );
 
  /* CV_RGB2GRAY: convert RGB image to grayscale */
  cvCvtColor( img, dst, CV_RGB2GRAY );
  /* create a window */
  cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
   
  /* display the image */
  cvShowImage( "image", dst );
   
  /* wait until user press a key */
  cvWaitKey(0);
   
  /* free memory */
  cvDestroyWindow( "image" );
  cvReleaseImage( &img );
  cvReleaseImage( &dst );
   
  return 0;
}
