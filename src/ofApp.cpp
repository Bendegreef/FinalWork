#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	w = 640;
	h = 480;
	ofSetWindowShape(w * 2, h);

	movie.initGrabber(w, h, true);

	rgb.allocate(w, h);
	hue.allocate(w, h);
	sat.allocate(w, h);
	bri.allocate(w, h);
	filtered.allocate(w, h);
	//output.load("blauwebloem.jpg");
	basisURL = "http://localhost/ofMysqltest/index.php?kleurnaam=";
	sender.init("My Sender");
}

//--------------------------------------------------------------
void ofApp::update(){
	movie.update();

	if (movie.isFrameNew()) {
		rgb.setFromPixels(movie.getPixels(), w, h);

		rgb.mirror(false, true);

		hsb = rgb;

		hsb.convertRgbToHsv();

		hsb.convertToGrayscalePlanarImages(hue, sat, bri);

		for (int i = 0; i<w*h; i++) {
			filtered.getPixels()[i] = ofInRange(hue.getPixels()[i], findHue - 2, findHue + 2) ? 255 : 0;
		}

		filtered.flagImageChanged();

		contours.findContours(filtered, 50, w*h, 1, false);
	}
	if (output.isAllocated()) {
		sender.send(output.getTexture());
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	rgb.draw(0, 0, w, h);
	ofPushStyle();
	contours.draw(0, 0, w, h);
	ofFill();
	ofPopStyle();
	if (output.isAllocated()) {
		output.draw(w, 0, w, h);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//calculate local mouse x,y in image
	int mx = x % w;
	int my = y % h;

	//get hue value on mouse position
	findHue = hue.getPixels()[my*w + mx];

	if (findHue < 23) {
		kleur = "oranje";
		getrequest = basisURL + kleur;
		resp = ofLoadURL(getrequest);
	}
	if (findHue > 22 && findHue < 39) {
		kleur = "geel";
		getrequest = basisURL + kleur;
		resp = ofLoadURL(getrequest);
	}
	if (findHue > 38 && findHue < 76) {
		kleur = "groen";
		getrequest = basisURL + kleur;
		resp = ofLoadURL(getrequest);
	}
	if (findHue > 75 && findHue < 131) {
		kleur = "blauw";
		getrequest = basisURL + kleur;
		resp = ofLoadURL(getrequest);
	}
	if (findHue > 130 && findHue < 161) {
		kleur = "violet";
		getrequest = basisURL + kleur;
		resp = ofLoadURL(getrequest);
	}
	if (findHue > 160 && findHue < 179) {
		kleur = "rood";
		getrequest = basisURL + kleur;
		resp = ofLoadURL(getrequest);
	}
	output.load(resp.data.getText());

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
