#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

class EventHandler {
public:
  void onSmokeDetected();  // Handle smoke detection event
  void onClear();          // Handle air quality clear event
};

#endif