#pragma once

#include <vector>
#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxXmlSettings.h"

#include "YAMPE/Particle.h"
#include "YAMPE/Particle/ContactGenerators.h"
#include "YAMPE/Particle/ForceGenerators.h"
#include "YAMPE/Particle/ForceGeneratorRegistry.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // simple 3D world with ground and axes
    const float RANGE = 16;
    ofEasyCam easyCam;
    float cameraHeightRatio = 0.02f;
    ofPoint easyCamTarget = ofPoint(0,5,0);
    void cameraHeightRatioChanged(float & cameraHeightRatio);
    
    ofPlanePrimitive ground;
    
    ofxImGui::Gui gui;                           // single entery to ImGUI subsystem
    ofRectangle mainWindowRectangle;        // used to ignore mouse drags for camera
    ofRectangle loggingWindowRectangle;     // used to ignore mouse drags for camera
    void drawAppMenuBar();
    void drawMainWindow();
    void drawLoggingWindow();
    
    // simimulation (generic)
    void reset();
    void quit();
    float t = 0.0f;
    bool isRunning = false;
    
    int n = 10;
    
    ofParameter<bool> isAxisVisible = true;
    ofParameter<bool> isXGridVisible = false;
    ofParameter<bool> isYGridVisible = true;;
    ofParameter<bool> isZGridVisible = false;;
    ofParameter<bool> isGroundVisible = true;
    ofParameter<bool> isFullScreen;
    ofParameter<std::string> position;
    
    // TODO - simimulation (specific stuff)
    YAMPE::ParticleRegistry balls;
    
    
    YAMPE::P::ForceGeneratorRegistry forceRegistry;
    YAMPE::P::GravityForceGenerator::Ref gravity;
    
    YAMPE::P::ContactRegistry::Ref contacts;
    YAMPE::P::GroundContactGenerator groundContact;
    YAMPE::P::ParticleParticleContactGenerator particleContact;
private:
    
    // or here
    
};
