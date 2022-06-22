#include <SDL2/SDL.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>

struct ball
{
	double pos_x;
	double pos_y;
	double vel;
	int strength;
};

struct paddle
{
	int height;
	int width;
	double pos_x;
	double vel;
};

struct bricks
{
	int height;
	int width;
	double pos_x;
	double pos_y;
	int hardness;
};

struct score
{
	int lifes;
	int points;
	int time;
};

SDL_Texture *loadtexture(const char *file,SDL_Renderer *renderer){

	SDL_Surface *surface=IMG_Load(file);
	SDL_Texture *texture=SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	return texture;

}

int main()
{
	
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO);

	SDL_Window *window = SDL_CreateWindow("Atari Breakout",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,720,720, SDL_WINDOW_OPENGL); 

	SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	
	SDL_Texture *background = loadtexture("./pxArt.png",renderer);

	
	SDL_Texture *paddle_texture = loadtexture("./green.png",renderer);

	SDL_Rect paddle_object;

	paddle_object.x=340;
    paddle_object.y=490;
    paddle_object.h=10;
    paddle_object.w=40;


	SDL_Texture *ball_texture = loadtexture("./pokeball.png",renderer);

	SDL_Rect ball_object;

	ball_object.x=340;
    ball_object.y=100;
    ball_object.h=10;
    ball_object.w=10;

	int n=1;

	while(n){
		SDL_RenderClear(renderer);
		SDL_Event event;
		if (SDL_PollEvent(&event)){
			if (event.type==SDL_QUIT)
			{
				n=0;
			}
			else if(event.type == SDL_KEYDOWN)
            {
                switch(event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                	if (paddle_object.x<490)
                	{
                		paddle_object.x +=10;
                	}  
                break;
               
                case SDLK_LEFT:
                	if (paddle_object.x>200)
                	{
                		paddle_object.x -=10;
                	}  
                break;
                }


            }



		}

		ball_object.y+=2;

		SDL_RenderCopy(renderer,background,NULL,NULL);

		SDL_RenderCopy(renderer,paddle_texture,NULL,&paddle_object);

		SDL_RenderCopy(renderer,ball_texture,NULL,&ball_object);

		SDL_Delay(16);

		SDL_RenderPresent(renderer);
	}


	return 0;
}