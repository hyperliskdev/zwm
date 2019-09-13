//
// Created by cartert on 2019-09-13.
//

#include "window_manager.hpp"
#include <glog/logging.h>

using ::std::unique_ptr;

unique_ptr<WindowManager> WindowManager::Create() {
    // 1. Open X display.
    Display* display = XOpenDisplay(nullptr);
    if (display == nullptr) {
        LOG(ERROR) << "Failed to open X display " << XDisplayName(nullptr);
        return nullptr;
    }
    // 2. Construct WindowManager instance.
    return unique_ptr<WindowManager>(new WindowManager(display));
}

WindowManager::WindowManager(Display* display)
        : display_(CHECK_NOTNULL(display)),
          root_(DefaultRootWindow(display_)) {
}

WindowManager::~WindowManager() {
    XCloseDisplay(display_);
}

void WindowManager::Run() { /* TODO */ }

void WindowManager::Run() {
    // INIT
    wm_detected_ = false;
    XSetErrorHandler(&WindowManager::OnWMDetected);
    XSelectInput(
            display_,
            root_,
            SubstructureRedirectMask | SubstructureNotifyMask)


}