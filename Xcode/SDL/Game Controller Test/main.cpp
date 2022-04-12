#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, const char * argv[]) {
    
    // Initialize SDL
    int err = SDL_Init(SDL_INIT_EVERYTHING);
    assert(!err);
    
    // Wait for device to connect
    SDL_Event evt;
    do {
        SDL_PollEvent(&evt);
    } while (evt.type != SDL_JOYDEVICEADDED);
    std::cout << "Num Joysticks: " << SDL_NumJoysticks() << std::endl;
    
    // Open Joystick device
    SDL_Joystick *js = SDL_JoystickOpen(0);
    assert(js);
    std::cout << "Is controller: " << (int) SDL_IsGameController(0) << std::endl;

    // Open Game Controller
    SDL_GameController *gc = SDL_GameControllerOpen(0);
    assert(gc);
    std::cout << SDL_GameControllerName(gc) << std::endl;
    std::cout << "Has rumble: " << (int) SDL_GameControllerHasRumble(gc) << std::endl;
    
    // Rumble the controller
    SDL_GameControllerRumble(gc, 0xFFFF, 0xFFFF, 500);

    // Run loop
    for(;;) {
        SDL_PollEvent(&evt);
    }
    
    return 0;
}
