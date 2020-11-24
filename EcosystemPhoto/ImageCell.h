#pragma once
#include "BaseCell.h"
class ImageCell :
    public BaseCell
{
public:
    ImageCell();
    ImageCell(Point pos, String path);

    void setTexture();

    void update();
};