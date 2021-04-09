/*
    Every house in a colony has at most 1 pipe going into it AND 1 pipe coming out of it
    Tanks and taps are to be installed such that
        -> Every house with 1 outgoing pipe and no incoming pipe gets a tank installed on its roof
        -> Every house with 1 incoming pipe and no outgoing pipe gets a tap installed

    Given - n (number of houses), p (number of pipes), arrays (a[], b[] and d[]) where d[i] denotes diameter of ith pipe from house a[i] to b[i]
    Return - array of pair of tanks and taps to be installed

*/