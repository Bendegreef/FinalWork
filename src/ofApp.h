

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxSpout.h"

class ofApp : public ofBaseApp{

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

		ofVideoGrabber movie;

		//ofImage grabscreen;
		ofxCvColorImage hsb, rgb;
		ofxCvGrayscaleImage hue, sat, bri, filtered;
		ofxCvContourFinder contours;

		int w, h, mx, my;
		int findHue, findBri, findSat, circlex, circley;
		float colorHeight, colorTop;
		ofHttpResponse resp;
		string basisURL, kleur, getrequest, kleurnaam;

		ofPixels pixels;
		ofTexture outputTex;
		ofImage output;
		ofFile imgFile;

		ofxSpout::Sender sender;
};
