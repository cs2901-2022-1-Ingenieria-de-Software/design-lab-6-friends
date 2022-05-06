#include <iostream>
#include <vector>
using namespace std;

class Light{
    protected:
        bool activated;
        string name;
    public:
        Light(){
            activated = false;
        }
        virtual void accion() = 0;
        string getName(){
            return name;
        }
        void TurnOn(){
            activated = true;
        }
        void TurnOff(){
          activated = false;
        }
};

class OrangeLED:public Light{
public:
    OrangeLED():Light(){
        name = "Orange_Led";
    }
    void accion() override{
        if(activated){
            cout<<"Orange on"<<endl;
            cout<<"Proximo a aterrizar"<<endl;
          }
        else
            cout<<"Orange off"<<endl; 
    }
};

class RedLed:public Light{
public:
    RedLed():Light(){
        name = "Red_Led";
    }
    void accion() override{
        if(activated){
            cout<<"Red on"<<endl;
            cout<<"Cuidado al aterrizar"<<endl;
          }
        else
            cout<<"Red off"<<endl;
    }
};

class GreenLED:public Light{
public:
    GreenLED(): Light(){
        name = "Green_Led";
    }
    void accion() override{
        if(activated){
            cout<<"Green on"<<endl;
            cout<<"Listo para despegar"<<endl;
          }
        else
            cout<<"Green off"<<endl;
    }
};

class StopLed:public Light{
    public:
        StopLed():Light(){
            name = "Stop_Led";
        }
        void accion() override{
            if(activated){
                cout<<"Stop Led on"<<endl;
                cout<<"Detente"<<endl;
              }
            else
                cout<<"Stop Led off"<<endl;
        }
};

class SystemControl{
protected:
    SystemControl(){}
    SystemControl(vector<Light*> _gadget){
        gadget = _gadget;
    }
    static SystemControl* system;
    vector<Light*> gadget;
public:
    SystemControl(SystemControl &other) = delete;
    void operator=(const SystemControl &) = delete; 
    static SystemControl *GetInstance();
    void setGadget(vector<Light*> _gadget){
        gadget = _gadget;
    }
    vector<Light*> getGadgets(){
        return gadget;
    }
    void activateGadget(string _gadget){
        for(int i=0; i<gadget.size(); i++)
            if(gadget[i]->getName() == _gadget){
                gadget[i]->TurnOn();
                gadget[i]->accion();
                gadget[i]->TurnOff();
              }
    }
};

SystemControl* SystemControl::system = nullptr;

SystemControl* SystemControl::GetInstance(){
    if(system == nullptr)
      system = new SystemControl();
    return system;
}

int main() {
    SystemControl*control = SystemControl::GetInstance();
    vector<Light*> gadgets;
    auto *n = new OrangeLED();
    auto *n1 = new RedLed();
    auto *n2 = new GreenLED();
    auto *stop = new StopLed();
    gadgets.push_back(n);
    gadgets.push_back(n1);
    gadgets.push_back(n2);
    gadgets.push_back(stop);
    control->setGadget(gadgets);
    control->activateGadget("Orange_Led");
    delete control;
    delete n;
    delete n1;
    delete n2;
    delete stop;
    return 0;
}