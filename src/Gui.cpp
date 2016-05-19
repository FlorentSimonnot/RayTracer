#include "Gui.hpp"
#include "Vector.hpp"
#include <SDL2/SDL.h>
#include <iostream>

Gui::Gui()
        : m_window(nullptr), m_renderer(nullptr) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Error when initialising: " << SDL_GetError() << std::endl;
        return;
    }

    m_window = SDL_CreateWindow("Projet Synthese", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH,
                                WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
    if (m_window == nullptr) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
    }

    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (m_renderer == nullptr) {
        std::cerr << "Could not create renderer: " << SDL_GetError() << std::endl;
    }

    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);
}

Gui::~Gui() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

void Gui::setPixel(int x, int y, Vector const& color) {
    SDL_SetRenderDrawColor(m_renderer, color.x(), color.y(), color.z(), SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(m_renderer, x, y);
}

void Gui::render() {
    SDL_RenderPresent(m_renderer);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(m_renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        SDL_WaitEvent(&event);
        if (event.type == SDL_QUIT)
            quit = 1;
    }
}

Gui::Gui(Gui const& g)
        : m_window(g.m_window),
          m_renderer(g.m_renderer) {
}

Gui& Gui::operator=(Gui const& g) {
    m_window = g.m_window;
    m_renderer = g.m_renderer;
    return *this;
}