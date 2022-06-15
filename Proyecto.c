#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>



int main()
{
	
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

	SDL_Window *window = SDL_CreateWindow("Test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480, SDL_WINDOW_OPENGL); 

	SDL_Renderer *render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	SDL_Surface *surface = IMG_Load("./Hello.jpg");

	SDL_Texture *texture = SDL_CreateTextureFromSurface(render,surface);

	int n=1;

	while(n){
		SDL_RenderClear(render);
		SDL_Event event;
		if (SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT)
			{
				n=0;
			}
		}

		SDL_RenderCopy(render,texture,NULL,NULL);

		SDL_RenderPresent(render);
	}


	return 0;
}