/*
Client --> Target (interface expected)
           ↑
        Adapter
           ↑
     Adaptee (existing class with different interface)

*/

#include <bits/stdc++.h>
using namespace std;
// Adaptee (incompatible interface)
class PenDrive {
public:
    void connectWithPenDrive() {
        cout << "Connected using PenDrive\n";
    }
};

// Target (expected interface)
class USBTypeC {
public:
    virtual void connect() = 0;
};

// Adapter
class PenDriveToTypeCAdapter : public USBTypeC {
private:
    PenDrive* penDrive;
public:
    PenDriveToTypeCAdapter(PenDrive* p) : penDrive(p) {}
    void connect() override {
        penDrive->connectWithPenDrive();  // Delegates call
    }
};


int main(){
     PenDrive* pen = new PenDrive();
    USBTypeC* usb = new PenDriveToTypeCAdapter(pen);

    usb->connect();  // Output: Connected using PenDrive

    delete usb;
    delete pen;
return 0;
}