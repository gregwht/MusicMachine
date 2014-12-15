/*
 -----------------------------------------------
 ||                                           ||
 ||               MUSIC MACHINE               ||
 ||              Clock Component              ||
 ||                                           ||
 -----------------------------------------------
 
                By Gregory White

 With thanks to Nuno Correia, Rebecca Fiebrink, and the Goldsmiths MA Computational Arts students. */


#pragma once

#include "ofMain.h"

#define BLOCK_NUM 12

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //--Sound-------------------
    ofSoundPlayer sample;
    
    
    //--Ring--------------------
    
    struct ringStruct {
        
        float x, y, r;
    };
    
    ringStruct ring;
    

    //--Beater-------------------
    
    struct beaterStruct {
        
        float x, y, r;
        int red, green, blue;
    };
    
    beaterStruct beater;
    
    
    //--Block--------------------
    
    struct blockStruct {
        float x, y, w, h;
        bool on;
        bool hover; // Whether or not the mouse is hovering within the area around the block, as determined by hoverSize
    };
    
    blockStruct block[BLOCK_NUM];

    float hoverSize;
   
    //--Collision---------------
    int frameSpeed;
    float angle, prevAngle;
    float angle180, prevAngle180;   // Since block 0 (or the number 12 is using the clock face analogy) is positioned where the angle changes from 359 to 0, we are unable to use the same if statement to check if the new angle is greater than the previous angle. Therefore, create two new floats with an offset of 180 (applied by adding 180 to the frameSpeed).
    float speed;
    

};

