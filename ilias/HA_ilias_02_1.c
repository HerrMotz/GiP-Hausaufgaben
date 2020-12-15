/*
 * Examples of gnuplot_i.c usage
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "gnuplot_i.c"

#define SLEEP_LGTH  500
#define NPOINTS     50

int main(int argc, char *argv[])
{
    gnuplot_ctrl    *   h1,
            *   h2,
            *   h3,
            *   h4 ;
    double              x[NPOINTS] ;
    double              y[NPOINTS] ;
    int                 i ;

    /*
     * Initialize the gnuplot handle
     */
    printf("*** example of gnuplot control through C ***\n") ;
    h1 = gnuplot_init() ;

    gnuplot_resetplot(h1) ;
    gnuplot_setstyle(h1, "impulses") ;
    printf("\n\n") ;
    printf("*** user-defined lists of doubles\n") ;

    x[0] = 100;
    for (i=1 ; i<NPOINTS ; i++) {
        x[i] = (double) x[i-1] / 3 + 1 ;
    }

    gnuplot_plot_x(h1, x, NPOINTS, "a_{n+1} = a_n/3 + 1") ;
    gnuplot_set_xlabel(h1, "n");
    gnuplot_set_ylabel(h1, "a_n");

    gnuplot_cmd(h1, "set autoscale");
    gnuplot_cmd(h1, "show autoscale");
    sleep(SLEEP_LGTH) ;


    /*
     * close gnuplot handles
     */


    printf("\n\n") ;
    printf("*** end of gnuplot example\n") ;
    gnuplot_close(h1) ;
    return 0 ;
}