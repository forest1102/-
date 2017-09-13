#pragma once
///////////////////////////////////////////////////////////////////////
//
//  �Q�[���̊�{���
//
namespace GameInfo
{
	// �Q�[���̃^�C�g��
	const String Title = L"Biscuit Clicker";

	// �Q�[���̃o�[�W�����i��̕������ OK�j
	const String Version = L"";

	// �Q�[���� Web �T�C�g�i�����ꍇ�͋�̕�����ɂ���j
	const String WebURL = L"";

	// ���ʃc�C�[�g�̕��́iTweetHead + score + TweetTail)
	const String TweetHead = L"";

	const String TweetTail = L"";

	// �Q�[���̔w�i�F
	const ColorF BackgroundColor = ColorF(0.4, 0.7, 0.5);

	// �V�[���؂�ւ����̃t�F�[�h�C���E�A�E�g�̐F
	const ColorF FadeInColor = ColorF(1.0, 1.0, 1.0);

	// �^�C�g���̃t�H���g�T�C�Y
	const int32 TitleFontSize = 72;

	// ���j���[�̃t�H���g�T�C�Y
	const int32 MenuFontSize = 24;

	// �Z�[�u�f�[�^�̕ۑ��ꏊ
	const FilePath SaveFilePath = L"Save/Score.dat";

	const int MAX_SCORE_SIZE = 5;

	// �X�^�b�t���[���̃N���W�b�g�i���ڂ͑����ł���j
	const Array<std::pair<String, Array<String>>> Credits
	{
		{ L"�Q�[���f�U�C��",{ L"Aaa Aaaa" } },
		{ L"�v���O����",{ L"Bbb Bbbb", L"Cccc Cccccc" } },
		{ L"�Q�[���A�[�g",{ L"Ddddd Ddddd" } },
		{ L"���y",{ L"Eeeee Eeee" } },
		{ L"Special Thanks",{ L"You!" } },
	};
}

///////////////////////////////////////////////////////////////////////
//
//  �S�ẴV�[������A�N�Z�X�ł���f�[�^
//
struct GameData
{
	int32 lastScore = 0;
};

using MyApp = SceneManager<String, GameData>;

///////////////////////////////////////////////////////////////////////
//
//  �Z�[�u�p�X�R�A�f�[�^
//
struct ScoreData
{
	int32 score;

	Date date;

	template <class Archive>
	void serialize(Archive& archive)
	{
		archive(score, date);
	}
};

