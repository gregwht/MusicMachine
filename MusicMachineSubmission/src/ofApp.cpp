#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // Initialise environment
    ofBackground(255);
    ofSetCircleResolution(100);
    
    // Initialise sound
    sample.loadSound("knock.mp3");
    sample.setMultiPlay(true);
    
    // Initialise ring
    ring.x = ofGetWidth()/2;
    ring.y = ofGetHeight()/2;
    ring.r = 300;
    
    // Initialise beater
    beater.x = ofGetWidth()/2;
    beater.y = ofGetHeight()/2 - ring.r;
    beater.r = 15;

    beater.red = 0;
    beater.blue = 0;
    beater.green = 0;
    
    // Initialise collision
    speed = 1;
    frameSpeed = ofGetFrameNum() * speed;
    angle = frameSpeed % 360;
    prevAngle = frameSpeed % 360;
    angle180 = (frameSpeed % 360) + 180;
    prevAngle180 = (frameSpeed % 360) + 180;
    
    // Initialise blocks
    ofSetRectMode(OF_RECTMODE_CENTER);
    for (int i = 0; i < BLOCK_NUM; i++){
        block[i].x = ofGetWidth()/2;
        block[i].y = ofGetHeight()/2 - ring.r;
        block[i].w = 2;
        block[i].h = 40;
        block[i].on = false;
        block[i].hover = false;
    }
    
    
    // Initialise boxes
    hoverSize = 50;
    
}

//--------------------------------------------------------------
void ofApp::update(){

    // Update collision variables
    prevAngle = angle;
    prevAngle180 = angle180;
    frameSpeed = ofGetFrameNum() * speed;
    angle = frameSpeed % 360;
    angle180 = (frameSpeed + 180) % 360;
    printf("Angle 180: %f \n", angle180);
    
// Check for collision

    // Check for collision on block[0]
    if (block[0].on == true){
        if (prevAngle180 < 180 && angle180 >= 180) {
            printf("Hit: %f \n", angle180);
            sample.play();
            beater.red = 255;
            beater.blue = 0;
            beater.green = 180;
        } else {
            beater.red = 0;
            beater.blue = 0;
            beater.green = 0;
        }
    }
    // Check for collision on rest of blocks
    for (int i = 0; i < BLOCK_NUM; i++){
        if (block[i].on == true){
            if (prevAngle < 30*i && angle >= 30*i) {
                printf("Hit: %f \n", angle);
                sample.play();
                beater.red = 255;
                beater.blue = 0;
                beater.green = 180;
            } else {
                beater.red = 0;
                beater.blue = 0;
                beater.green = 0;
            }
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    //--Draw ring-----------------------------------------------
    ofSetColor(0);
    ofNoFill();
    ofCircle(ring.x, ring.y, ring.r);
    
    
    //--Draw centre point---------------------------------------
    ofFill();
    ofCircle(ring.x, ring.y, 5);
    
    
    //--Draw blocks---------------------------------------------
    for (int i = 0; i < BLOCK_NUM; i++){
        
        // Set colour depending on state
        if (block[i].on == true){ofSetColor(0);}
        
        else if (block[i].hover == true){ofSetColor(255, 0, 180, 150);}
        
        else {ofSetColor(0, 30);}
        
        // Rotate and draw blocks
        ofPushMatrix();
        ofTranslate(ring.x, ring.y);
        ofRotate(30 * i);
        ofRect(block[i].x - ring.x, block[i].y - ring.y, block[i].w, block[i].h);
        ofPopMatrix();
    }

    //--Draw beater---------------------------------------------
    ofSetColor(beater.red, beater.blue, beater.green);
    ofFill();
    
    ofPushMatrix();
    ofTranslate(ring.x, ring.y);
    ofRotateZ(frameSpeed);
    ofCircle(beater.x - ring.x, beater.y - ring.y, beater.r);
    
    //--Draw stick----------------------------------------------
    ofSetColor(0);
    ofLine(ring.x - ring.x, ring.y - ring.y, beater.x - ring.x, beater.y - ring.y);

    ofPopMatrix();

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    // Change speed
    
    if (key == '='){
        speed *= 1.1;
    }
    
    if (key == '-'){
        speed *= 0.9;
    }
    
    printf("Speed: %f \n", speed);
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

// ATTEMPED CODE TO AUTOMATE CREATION OF HOVER AREAS
//
//    for (int i = 0; i < BLOCK_NUM; i++){
//
//      ofPushMatrix();
//      ofTranslate(ring.x, ring.y);
//      ofRotate(30 * i);
//          if (mouseX >= block[i].x - hoverSize &&
//              mouseX <= block[i].x + hoverSize &&
//              mouseY >= block[i].y - hoverSize &&
//              mouseY <= block[i].y + hoverSize) {
//            
//                  block[i].hover = true;
//
//          } else {block[i].hover = false;}
//
//      ofPopMatrix();
//
//    }



    
    if (mouseX >= ofGetWidth()/2 - hoverSize &&
        mouseX <= ofGetWidth()/2 + hoverSize &&
        mouseY >= ofGetHeight()/2 - ring.r - hoverSize &&
        mouseY <= ofGetHeight()/2 - ring.r + hoverSize) {
        
        block[0].hover = true;
    } else { block[0].hover = false; }
    
    
    if (mouseX >= 534 - hoverSize &&
        mouseX <= 534 + hoverSize &&
        mouseY >= 123 - hoverSize &&
        mouseY <= 123 + hoverSize) {
        
        block[1].hover = true;
    } else { block[1].hover = false; }

    
    if (mouseX >= 645 - hoverSize &&
        mouseX <= 645 + hoverSize &&
        mouseY >= 235 - hoverSize &&
        mouseY <= 235 + hoverSize) {
        
        block[2].hover = true;
    } else { block[2].hover = false; }

    
    if (mouseX >= ofGetWidth()/2 + ring.r - hoverSize &&
        mouseX <= ofGetWidth()/2 + ring.r + hoverSize &&
        mouseY >= ofGetHeight()/2 - hoverSize &&
        mouseY <= ofGetHeight()/2 + hoverSize) {
        
        block[3].hover = true;
    } else { block[3].hover = false; }

    
    if (mouseX >= 645 - hoverSize &&
        mouseX <= 645 + hoverSize &&
        mouseY >= 536 - hoverSize &&
        mouseY <= 536 + hoverSize) {
        
        block[4].hover = true;
    } else { block[4].hover = false; }
    
    
    if (mouseX >= 534 - hoverSize &&
        mouseX <= 534 + hoverSize &&
        mouseY >= 645 - hoverSize &&
        mouseY <= 645 + hoverSize) {
        
        block[5].hover = true;
    } else { block[5].hover = false; }
    
    
    if (mouseX >= ofGetWidth()/2 - hoverSize &&
        mouseX <= ofGetWidth()/2 + hoverSize &&
        mouseY >= ofGetHeight()/2 + ring.r - hoverSize &&
        mouseY <= ofGetHeight()/2 + ring.r + hoverSize) {
        
        block[6].hover = true;
    } else { block[6].hover = false; }
    
    
    if (mouseX >= 235 - hoverSize &&
        mouseX <= 235 + hoverSize &&
        mouseY >= 645 - hoverSize &&
        mouseY <= 645 + hoverSize) {
        
        block[7].hover = true;
    } else { block[7].hover = false; }
    
    
    if (mouseX >= 125 - hoverSize &&
        mouseX <= 125 + hoverSize &&
        mouseY >= 536 - hoverSize &&
        mouseY <= 536 + hoverSize) {
        
        block[8].hover = true;
    } else { block[8].hover = false; }
    
    
    if (mouseX >= ofGetWidth()/2 - ring.r - hoverSize &&
        mouseX <= ofGetWidth()/2 - ring.r + hoverSize &&
        mouseY >= ofGetHeight()/2 - hoverSize &&
        mouseY <= ofGetHeight()/2 + hoverSize) {
        
        block[9].hover = true;
    } else { block[9].hover = false; }

    
    if (mouseX >= 125 - hoverSize &&
        mouseX <= 125 + hoverSize &&
        mouseY >= 235 - hoverSize &&
        mouseY <= 235 + hoverSize) {
        
        block[10].hover = true;
    } else { block[10].hover = false; }
    
    
    if (mouseX >= 235 - hoverSize &&
        mouseX <= 235 + hoverSize &&
        mouseY >= 123 - hoverSize &&
        mouseY <= 123 + hoverSize) {
        
        block[11].hover = true;
    } else { block[11].hover = false; }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

// ATTEMPED CODE TO AUTOMATE CREATION OF HOVER AREAS
//
//    for (int i = 0; i < BLOCK_NUM; i++){
//
//      ofPushMatrix();
//      ofTranslate(ring.x, ring.y);
//      ofRotate(30 * i);
//          if (mouseX >= block[i].x - hoverSize &&
//              mouseX <= block[i].x + hoverSize &&
//              mouseY >= block[i].y - hoverSize &&
//              mouseY <= block[i].y + hoverSize) {
//
//                  block[i].on = !block[i].on;
//          }
//
//      ofPopMatrix();
//
//    }
    

    if (mouseX >= ofGetWidth()/2 - hoverSize &&
        mouseX <= ofGetWidth()/2 + hoverSize &&
        mouseY >= ofGetHeight()/2 - ring.r - hoverSize &&
        mouseY <= ofGetHeight()/2 - ring.r + hoverSize) {
        
        block[0].on = !block[0].on;
    }
    
    if (mouseX >= 534 - hoverSize &&
        mouseX <= 534 + hoverSize &&
        mouseY >= 123 - hoverSize &&
        mouseY <= 123 + hoverSize) {
        
        block[1].on = !block[1].on;
    }
    
    if (mouseX >= 645 - hoverSize &&
        mouseX <= 645 + hoverSize &&
        mouseY >= 235 - hoverSize &&
        mouseY <= 235 + hoverSize) {
        
        block[2].on = !block[2].on;
    }
    
    if (mouseX >= ofGetWidth()/2 + ring.r - hoverSize &&
        mouseX <= ofGetWidth()/2 + ring.r + hoverSize &&
        mouseY >= ofGetHeight()/2 - hoverSize &&
        mouseY <= ofGetHeight()/2 + hoverSize) {
        
        block[3].on = !block[3].on;
    }

    if (mouseX >= 645 - hoverSize &&
        mouseX <= 645 + hoverSize &&
        mouseY >= 536 - hoverSize &&
        mouseY <= 536 + hoverSize) {
        
        block[4].on = !block[4].on;
    }
    
    if (mouseX >= 534 - hoverSize &&
        mouseX <= 534 + hoverSize &&
        mouseY >= 645 - hoverSize &&
        mouseY <= 645 + hoverSize) {
        
        block[5].on = !block[5].on;
    }
    
    if (mouseX >= ofGetWidth()/2 - hoverSize &&
        mouseX <= ofGetWidth()/2 + hoverSize &&
        mouseY >= ofGetHeight()/2 + ring.r - hoverSize &&
        mouseY <= ofGetHeight()/2 + ring.r + hoverSize) {
        
        block[6].on = !block[6].on;
    }
    
    if (mouseX >= 235 - hoverSize &&
        mouseX <= 235 + hoverSize &&
        mouseY >= 645 - hoverSize &&
        mouseY <= 645 + hoverSize) {
        
        block[7].on = !block[7].on;
    }
    
    if (mouseX >= 125 - hoverSize &&
        mouseX <= 125 + hoverSize &&
        mouseY >= 536 - hoverSize &&
        mouseY <= 536 + hoverSize) {
        
        block[8].on = !block[8].on;
    }
    
    if (mouseX >= ofGetWidth()/2 - ring.r - hoverSize &&
        mouseX <= ofGetWidth()/2 - ring.r + hoverSize &&
        mouseY >= ofGetHeight()/2 - hoverSize &&
        mouseY <= ofGetHeight()/2 + hoverSize) {
        
        block[9].on = !block[9].on;
    }
    
    if (mouseX >= 125 - hoverSize &&
        mouseX <= 125 + hoverSize &&
        mouseY >= 235 - hoverSize &&
        mouseY <= 235 + hoverSize) {
        
        block[10].on = !block[10].on;
    }
    
    if (mouseX >= 235 - hoverSize &&
        mouseX <= 235 + hoverSize &&
        mouseY >= 123 - hoverSize &&
        mouseY <= 123 + hoverSize) {
        
        block[11].on = !block[11].on;
    }
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}