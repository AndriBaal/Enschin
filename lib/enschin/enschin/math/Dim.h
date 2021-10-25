#pragma once

struct Dim {
	float w, h;
	Dim(float w = 0, float h = 0);
	float getRatioWH() { return w / h; }
	float getRatioHW() { return h / w; }
	Dim operator=(const Dim& newVector);
};