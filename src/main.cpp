#include <SDL.h>
#include <iostream>
#include "game.h"
#include "renderer.h"
#include <memory>

int main(int argc, char *argv[]) 
{
	
	constexpr int kFramesPerSecond{ 60 };
	constexpr int kMsPerFrame{ 1000 / kFramesPerSecond };
	constexpr int kScreenWidth{ 360 };
	constexpr int kScreenHeight{ 720 };

	std::unique_ptr<Renderer> renderer = std::unique_ptr<Renderer>(new Renderer(kScreenWidth, kScreenHeight));
	Game game;
	game.setRenderer(std::move(renderer));

	while(true)
	{
		if(!game.Run(kMsPerFrame))
			break;
	}
	return 0;
}