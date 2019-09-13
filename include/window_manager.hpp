//
// Created by cartert on 2019-09-13.
//

#ifndef ZWM_WINDOW_MANAGER_HPP
#define ZWM_WINDOW_MANAGER_HPP

extern "C" {
#include <X11/Xlib.h>
};

#include <memory>

class WindowManager {
public:
    static ::std::unique_ptr<WindowManager> Create();
    ~WindowManager();

    void Run();

    // Xlib error handler. It must be static as its address is passed to Xlib.
    static int OnXError(Display* display, XErrorEvent* e);
    // Xlib error handler used to determine whether another window manager is
    // running. It is set as the error handler right before selecting substructure
    // redirection mask on the root window, so it is invoked if and only if
    // another window manager is running. It must be static as its address is
    // passed to Xlib.
    static int OnWMDetected(Display* display, XErrorEvent* e);
    // Whether an existing window manager has been detected. Set by OnWMDetected,
    // and hence must be static.
    static bool wm_detected_;


private:
    WindowManager(Display* display);

    Display* display_;

    const Window root_;
};


#endif //ZWM_WINDOW_MANAGER_HPP
