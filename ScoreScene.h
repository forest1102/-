#pragma once

///////////////////////////////////////////////////////////////////////
//
//  �n�C�X�R�A�ꗗ
//
class Score : public MyApp::Scene
{
private:

	std::array<ScoreData, GameInfo::MAX_SCORE_SIZE> m_highScores;

public:

	void init() override;

	void update() override;

	void draw() const override;
};