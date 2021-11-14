#pragma once

/**
 * @brief 2Point Dimension (Width / Height)
 */
struct Dim2 {
    float w, h;
    Dim2(float w = 0, float h = 0);

    bool operator==(const Dim2& v);

    float getRatioWH() { return w / h; }
    float getRatioHW() { return h / w; }
};