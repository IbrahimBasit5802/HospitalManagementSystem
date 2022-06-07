#pragma once
#include <iostream>
using namespace std;

class FeedBack {
    char review[100];
    double rating;
    public:
    FeedBack() {

    }
    FeedBack(string r, double ra) {
        strcpy(review, r.c_str()); 
        rating = ra;   
    }
    double getRating() {
        return rating;
    }
    char * getReview() {
        return review;
    }
    void setReview(string r) {
        strcpy(review, r.c_str()); 
   
    }
    void setRating(double r) {
        rating  = r;
    }
    FeedBack operator=(FeedBack obj) {
        setRating(obj.getRating());
        setReview(obj.getReview());
    }
};