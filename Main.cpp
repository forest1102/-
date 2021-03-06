﻿
#include"_Header.h"



void Main()
{
	Window::Resize(1280, 720);
	Window::SetTitle(GameInfo::Title);
	Graphics::SetBackground(GameInfo::BackgroundColor);
	System::SetExitEvent(WindowEvent::CloseButton);

	//////////////////////////////////////////////////////////////
	//
	//  使用するシーン
	//
	MyApp manager;
	manager.setFadeColor(GameInfo::FadeInColor);
	manager.add<Title>(L"Title");
	manager.add<Game>(L"Game");
	manager.add<Result>(L"Result");
	manager.add<Score>(L"Score");
	manager.add<Credit>(L"Credit");

	//////////////////////////////////////////////////////////////
	//
	//  使用するフォント
	//
	FontAsset::Register(L"Title", GameInfo::TitleFontSize, Typeface::Heavy, FontStyle::Outline);
	FontAsset(L"Title").changeOutlineStyle(TextOutlineStyle(Color(60), Color(255), GameInfo::TitleFontSize * 0.05));
	FontAsset::Register(L"Menu", GameInfo::MenuFontSize, Typeface::Bold);
	FontAsset::Register(L"Version", 14, Typeface::Regular);
	FontAsset::Register(L"CountDown", 72, Typeface::Bold);
	FontAsset::Register(L"Result", 80, Typeface::Bold);
	FontAsset::Register(L"ResultButton", 32, Typeface::Regular);
	FontAsset::Register(L"GameTime", 40, Typeface::Light);
	FontAsset::Register(L"ScoreList", 50, Typeface::Heavy);
	FontAsset::Register(L"ScoreListDate", 25, Typeface::Regular, FontStyle::Italic);
	FontAsset::Register(L"CreditBig", 32, Typeface::Bold);
	FontAsset::Register(L"CreditSmall", 28, Typeface::Regular);

	//////////////////////////////////////////////////////////////
	//
	//  使用する画像・音楽
	//



	//////////////////////////////////////////////////////////////
	//
	//  メインループ
	//
	while (System::Update())
	{
		if (!manager.updateAndDraw())
		{
			break;
		}
	}
}
