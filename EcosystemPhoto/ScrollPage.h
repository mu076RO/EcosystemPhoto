#pragma once
#include <Siv3D.hpp>

class ScrollPage
{
private:
	int _scroll;	//�X�N���[������y���W
	int _bottomY;	//�X�N���[���̉���

	const int SPEED;	//�X�N���[�����x
	const int SCROLL_MERGIN;

public:
	ScrollPage();

	void reset(int bottomY);	//�����̐ݒ�
	void update();	//�X�V

	int scroll();	//�X�N���[���l�̎擾
};
