#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    bool result = Input.open("weather_Yokohama.txt");
    if(!result){
        cout << "faild to get Json data" << endl;
        
    }else{
        cout << Input["city"]["name"].asString() << endl;
        // cout <<Input.getRawString()<<endl;
        
        for(int i=0;i<30;i++){
            ofDrawBitmapString(Input["list"][i]["dt_txt"].asString(), 100, 30*i);
            cout << Input["list"][i]["dt_txt"].asString() << endl;
        };
    }
    Sender.setup( HOST, PORT );
    
    
    for(int i=0;i<38;i++){
        string M = Input["list"][i]["weather"][0]["main"].asString();
        if(M == "Clear"){
            kind[i] = 0;
        }else if(M == "Rain"){
            kind[i] = 1;
        }else if(M == "Clouds"){
            kind[i] = 2;
        }
    }
    
  
}

//--------------------------------------------------------------
void ofApp::update(){
    
    Sender.sendMessage(time);
    Sender.sendMessage(weather);
    Sender.sendMessage(rain);
    Sender.sendMessage(clouds);
    Sender.sendMessage(temp);
    Sender.sendMessage(wind);
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i=0;i<38 ;i++){
        ofDrawBitmapString(Input["list"][i]["dt_txt"].asString(), 50, 13*i+50);
        ofDrawBitmapString(Input["list"][i]["weather"][0]["main"].asString(), 250, 13*i+50);
        if(Input["list"][i]["weather"][0]["main"].asString() == "Rain"){
            ofDrawBitmapString(ofToString(Input["list"][i]["rain"]["3h"].asFloat()), 320, 13*i+50);
        }
        ofDrawBitmapString(ofToString(Input["list"][i]["clouds"]["all"].asInt()) + " %", 410, 13*i+50);
        ofDrawBitmapString(ofToString(Input["list"][i]["main"]["temp"].asInt()), 480, 13*i+50);
        ofDrawBitmapString(ofToString(Input["list"][i]["wind"]["speed"].asFloat()), 550, 13*i+50);
    };
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
    time.clear();
    weather.clear();
    rain.clear();
    clouds.clear();
    temp.clear();
    wind.clear();
    
    
    time.setAddress("/time");
    weather.setAddress("/weather");
    rain.setAddress("/rain");
    clouds.setAddress("/clouds");
    temp.setAddress("/temp");
    wind.setAddress("/wind");
    
    
    for(int i=0;i<38;i++){
        time.addStringArg(Input["list"][i]["dt_txt"].asString());
        time.addIntArg(i);
        weather.addIntArg(kind[i]);
        
        if(Input["list"][i]["weather"][0]["main"].asString() == "Rain"){
            rain.addFloatArg(Input["list"][i]["rain"]["3h"].asFloat());
        }else{
            rain.addIntArg(0);
        }
        
        clouds.addIntArg(Input["list"][i]["clouds"]["all"].asInt());
        temp.addIntArg(Input["list"][i]["main"]["temp"].asInt());
        wind.addIntArg(Input["list"][i]["wind"]["speed"].asFloat());
    }
    
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
