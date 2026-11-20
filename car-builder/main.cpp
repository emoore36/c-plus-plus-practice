#include <iostream>
using namespace std;

void println(string msg) { cout << msg << endl; }

class Car {
private:
  bool isEngineInstalled = false;
  bool isRunning = false;

public:
  void installEngine() {
    println("Attempting to install engine...");
    if (isEngineInstalled) {
      println("There's already an engine in here.");
      return;
    }

    isEngineInstalled = true;
    println("Engine has been installed.");
  }

  void uninstallEngine() {
    println("Attempting to uninstall engine...");
    if (isRunning) {
      println("Don't remove the engine while the car's running!");
      return;
    }
    if (!isEngineInstalled) {
      println("There's no engine in here to remove.");
      return;
    }

    isEngineInstalled = false;
    println("Engine has been removed.");
  }

  void startEngine() {
    println("Attempting to start the car...");
    if (!isEngineInstalled) {
      println("Can't start the car without an engine in it.");
      return;
    }
    if (isRunning) {
      println("The car is already running.");
      return;
    }

    isRunning = true;
    println("Okay. The car is running.");
  }

  void stopEngine() {
    println("Attempting to stop the car...");
    if (!isRunning) {
      println("It's already off.");
      return;
    }

    isRunning = false;
    println("Okay. The car is no longer running.");
  }
};

int main() {
  println("Hello world!");
  Car myCar;
  Car secondCar;

  println("");
  println("Testing time:");
  println("");

  // happy path
  myCar.installEngine();
  myCar.startEngine();
  myCar.stopEngine();
  myCar.uninstallEngine();

  println("");
  println("Mishap time:");
  println("");

  // several mishaps
  myCar.startEngine();
  myCar.stopEngine();
  myCar.uninstallEngine();

  println("");
  println("Multi-car time:");
  println("");

  // test multiple instances
  myCar.installEngine();
  secondCar.startEngine();

  return 0;
}