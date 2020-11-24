#pragma once
#include "BaseCell.h"

class FolderCell :
    public BaseCell
{
private:
    bool _reloadFlag;

public:
    FolderCell();
    FolderCell(Point pos, String path);

    void setTexture();	//�摜�̐ݒ�

    void update();

    bool reloadFlag();
};

