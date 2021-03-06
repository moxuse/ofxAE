#pragma once

#include "ofxAEDef.h"
#include "ofxAEAVLayerCap.h"
#include "ofVideoPlayer.h"

OFX_AE_NAMESPACE_BEGIN

class Composition;

class MovieCap : public AVCap
{
public:
	MovieCap(AVLayer *layer);
	void loadMovie(const string& filepath);
	void setComposition(Composition *comp) { comp_=comp; }
	void setActive(bool active);
	void setUseAudio(bool use_audio);
	void update();
	void draw(float alpha=1);
private:
	ofVideoPlayer movie_;
	Composition *comp_;
	float frame_rate_;
	bool use_audio_;
	float lazy_seconds_;
};

OFX_AE_NAMESPACE_END
/* EOF */