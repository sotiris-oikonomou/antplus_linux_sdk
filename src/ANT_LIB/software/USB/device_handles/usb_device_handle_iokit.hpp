/*
This software is subject to the license described in the License.txt file
included with this software distribution. You may not use this file except
in compliance with this license.

Copyright (c) Dynastream Innovations Inc. 2016
All rights reserved.
*/
#ifndef USB_DEVICE_HANDLE_IOKIT_HPP
#define USB_DEVICE_HANDLE_IOKIT_HPP

#include "types.h"
#include "dsi_thread.h"

#include "usb_device_handle.hpp"
#include "usb_device_iokit.hpp"
#include "usb_device_list.hpp"

#include "iokit_device_handle.hpp"
#include "iokit_device.hpp"


#include "dsi_ts_queue.hpp"


//////////////////////////////////////////////////////////////////////////////////
// Public Definitions
//////////////////////////////////////////////////////////////////////////////////

typedef USBDeviceList<const USBDeviceIOKit*> USBDeviceListIOKit;


//////////////////////////////////////////////////////////////////////////////////
// Public Class Prototypes
//////////////////////////////////////////////////////////////////////////////////

class USBDeviceHandleIOKit : public USBDeviceHandle
{
   private:

      TSQueue<char> clRxQueue;

      // Thread Variables
      DSI_THREAD_ID hReceiveThread;                         // Handle for the receive thread.
      DSI_MUTEX stMutexCriticalSection;                     // Mutex used with the wait condition
      DSI_CONDITION_VAR stEventReceiveThreadExit;           // Event to signal the receive thread has ended.
      BOOL bStopReceiveThread;                              // Flag to stop the receive thread.


      // Device Variables
      IOKitDeviceHandle* pclDeviceHandle;
      USBDeviceIOKit clDevice;
      BOOL bDeviceGone;

      // Private Member Functions
      BOOL POpen();
      void PClose(BOOL bReset_ = FALSE);
      void ReceiveThread();
      static DSI_THREAD_RETURN ProcessThread(void *pvParameter_);


      static USBDeviceList<const USBDeviceIOKit> clDeviceList;  //This holds only instances of USBDeviceIOKit (unless someone manually makes their own)


      static BOOL GetNextModemPath(io_iterator_t hSerialPortIterator_, char* pcBSDPath, CFIndex iMaxPathSize);
      static BOOL FindModems(io_iterator_t* phMatchingServices_);

      static BOOL CanOpenDevice(const USBDeviceIOKit*const & pclDevice_);

      //!!Const-correctness!
   public:

      static const USBDeviceListIOKit GetAllDevices();  //!!List copy!   //!!Should we make the list static instead and return a reference to it?
      static const USBDeviceListIOKit GetAvailableDevices();  //!!List copy!

      static BOOL Open(const USBDeviceIOKit& clDevice_, USBDeviceHandleIOKit*& pclDeviceHandle_);  //should these be member functions?
      static BOOL Close(USBDeviceHandleIOKit*& pclDeviceHandle_, BOOL bReset_ = FALSE);
      static BOOL TryOpen(const USBDeviceIOKit& clDevice_);

      static UCHAR GetNumberOfDevices();


      // Methods inherited from the base class:
      USBError::Enum Write(void* pvData_, ULONG ulSize_, ULONG& ulBytesWritten_);
      USBError::Enum Read(void* pvData_, ULONG ulSize_, ULONG& ulBytesRead_, ULONG ulWaitTime_);

      const USBDevice& GetDevice() { return clDevice; }


   protected:

      USBDeviceHandleIOKit(const USBDeviceIOKit& clDevice_);
      virtual ~USBDeviceHandleIOKit();

      const USBDeviceHandleIOKit& operator=(const USBDeviceHandleIOKit& clDevicehandle_) { return clDevicehandle_; }  //!!NOP

};

#endif // !defined(USB_DEVICE_HANDLE_VCP_HPP)

