#pragma once
// Trạng thái Object
extern enum State
{
	MOVING,					// Di chuyển
	STANDING,				// Đứng yên
	RUNNING,				// Chạy
	JUMPING,				// Nhảy
	FALLING,				// Rơi
	SITTING,				// Nằm
	ATTACKING,				// Tấn công
	ATTACKING_STAND,		// Tấn công đứng
	ATTACKING_SIT,			// Tấn công nằm
	THROWING,				// Ném
	CLINGING,				// Bám
	CLIMBING,				// Leo
	FLYING,					// Bay
	ACTIVE,					// Active
	DEAD,					// Chết
	INJURED					// Bị thương
};