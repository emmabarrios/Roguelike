#pragma once

// I think this can be a struct
class Vector2 {
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	Vector2& Add(const Vector2& vec);
	Vector2& Subtract(const Vector2& vec);
	Vector2& Multiply(const Vector2& vec);
	Vector2& Divide(const Vector2& vec);

	// what the fuck is friend
	friend Vector2& operator + (Vector2& v1, Vector2& v2);
	friend Vector2& operator - (Vector2& v1, Vector2& v2);
	friend Vector2& operator * (Vector2& v1, Vector2& v2);
	friend Vector2& operator / (Vector2& v1, Vector2& v2);

	Vector2& operator += (const Vector2& vec);
	Vector2& operator -= (const Vector2& vec);
	Vector2& operator *= (const Vector2& vec);
	Vector2& operator /= (const Vector2& vec);

	Vector2& operator * (const int& i);

	Vector2& Zero();
};