#include "text.hpp"

TextMessage::TextMessage(SDL_Renderer* passed_renderer, std::string message, int x, int y) //Constructor
{
    renderer = passed_renderer;

    X_pos = x;
    Y_pos = y;

    origin_x = 0;
    origin_y = 0;


    if (TTF_Init() != 0){
        //logSDLError(std::cout, "TTF_Init");
        SDL_Quit();
    }
    SDL_Color color = { 255, 255, 255, 255 };
    textTexture = renderText(message, "fontFile.ttf", color, 64, passed_renderer);
}

TextMessage::~TextMessage() //Destructor
{
        SDL_DestroyTexture(textTexture);
}

SDL_Texture* TextMessage::renderText(const std::string &message, const std::string &fontFile,
                                     SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
    //Open the font
    TTF_Font *font = TTF_OpenFont("fontFile.ttf", fontSize);
    if (font == NULL){
        std::cout << "TTF_OpenFont";
        return nullptr;
    }
    //We need to first render to a surface as that's what TTF_RenderText
    //returns, then load that surface into a texture
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr){
        TTF_CloseFont(font);
        //logSDLError(std::cout, "TTF_RenderText");
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr){
        //logSDLError(std::cout, "CreateTexture");
    }

    rect = { 0, 0, surf->w, surf->h };
    crop = { 0, 0, surf->w, surf->h };
    //Clean up the surface and font
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

void TextMessage::Draw(){
    SDL_RenderCopy(renderer, textTexture, &rect, &crop);
}
