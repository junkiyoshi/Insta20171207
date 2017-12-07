#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Insta");

	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	
	float radius = 180;
	float circle_weight = 180;
	float x, y;
	float noise_value;
	ofColor body_color;

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	
	for (int color_value = 0; color_value < 240; color_value += 80) {

		body_color.setHsb(color_value, 255, 255);
		ofSetColor(body_color);

		ofBeginShape();

		for (float deg = 0; deg <= 360; deg += 1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);
			noise_value = ofNoise(x * 0.05, y * 0.05, color_value, ofGetFrameNum() * 0.025);

			if (noise_value > 0.01) {
				x = (radius + (circle_weight * noise_value)) * cos(deg * DEG_TO_RAD);
				y = (radius + (circle_weight * noise_value)) * sin(deg * DEG_TO_RAD);
			}
			else {
				noise_value = 0.01;
				x = (radius + (circle_weight * noise_value)) * cos(deg * DEG_TO_RAD);
				y = (radius + (circle_weight * noise_value)) * sin(deg * DEG_TO_RAD);
			}

			ofVertex(x, y);
		}

		for (float deg = 360; deg >= 0; deg -= 1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);

			ofVertex(x, y);
		}

		ofEndShape();
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}