#pragma once
#include <Siv3D.hpp>

class ScrollPage
{
private:
	double _scroll;	//�X�N���[������y���W
	double _bottomY;	//�X�N���[���̉���

	const double SPEED;	//�X�N���[�����x

public:
	ScrollPage();

	void reset(double bottomY);	//�����̐ݒ�
	void update();	//�X�V

	double scroll();	//�X�N���[���l�̎擾
};
