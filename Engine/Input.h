#pragma once

enum class KEY_TYPE
{
	// VK_UP 같은 것은 WINDOWS에서 제공하는 키매핑.
	UP = VK_UP,
	DOWN = VK_DOWN,
	LEFT = VK_LEFT,
	RIGHT = VK_RIGHT,
	W = 'W',
	A = 'A',
	S = 'S',
	D = 'D',
};

enum class KEY_STATE
{
	NONE,
	PRESS,
	DOWN,
	UP,
	END
};

enum
{
	KEY_TYPE_COUNT = static_cast<int32>(UINT8_MAX),
	KEY_STATE_COUNT = static_cast<int32>(KEY_STATE::END),
};

class Input
{
public:
	void Init(HWND hwnd);
	void Update();

	// 누르고 있을 때
	bool GetButton(KEY_TYPE key) { return GetState(key) == KEY_STATE::PRESS; }
	// 맨 처음 눌렀을 때
	bool GetButtonDown(KEY_TYPE key) { return GetState(key) == KEY_STATE::DOWN; }
	// 맨 처음 눌렀다 뗐을 때
	bool GetButtonUp(KEY_TYPE key) { return GetState(key) == KEY_STATE::UP; }

private:
	inline KEY_STATE GetState(KEY_TYPE key) { return _states[static_cast<uint8>(key)]; }

private:
	HWND _hwnd;
	// 현재 누른 상태를 확인하는 벡터.
	vector<KEY_STATE> _states;
};

