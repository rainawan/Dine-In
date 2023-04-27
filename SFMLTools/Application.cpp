//
// Created by Raina Wan on 4/18/23.
//

#include "Application.h"

Application::Application() : window({2500,1500, 32}, "Dine-In") {

}

Application::Application(sf::VideoMode videoMode, std::string title) : window(videoMode, title) {

}

void Application::eventListener() {

}

void Application::runLoop() {
    HomePage home;

    ReservationPage item(RestaurantItem("Test", {1400, 250}, BONE_KETTLE, FIVESTAR, 4), BK_INSIDE);


    while(window.isOpen()) {

        sf::Event event;
        while(window.pollEvent(event)) {
            if(sf::Event::Closed == event.type)
                window.close();
            home.eventHandler(window, event);
            item.eventHandler(window, event);
        }

        home.update();
        window.clear(sf::Color::Black);
        window.draw(home);
        window.display();
    }
}

void Application::addDrawable(GUIComponent &object) {
    objects.push_back(&object);
}
