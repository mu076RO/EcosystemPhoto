#pragma once
#include "BaseCell.h"
class FolderCell :
    public BaseCell
{
public:
    FolderCell();
    FolderCell(Point pos, String path);

    void setTexture();	//�摜�̐ݒ�

    void update();
};

