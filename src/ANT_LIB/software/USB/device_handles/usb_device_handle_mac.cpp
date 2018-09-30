/*
This software is subject to the license described in the License.txt file
included with this software distribution. You may not use this file except
in compliance with this license.

Copyright (c) Dynastream Innovations Inc. 2016
All rights reserved.
*/
#include "types.h"
#if defined(DSI_TYPES_MACINTOSH)


#include "usb_device_handle.hpp"

#include "macros.h"
#include "antmessage.h"

#include "usb_device_handle_vcp.hpp"
#include "usb_device_handle_si_iokit.hpp"
#include "usb_device_handle_iokit.hpp"

#if defined(LIBUSB_DRIVER)
#include "usb_device_handle_libusb_mac.hpp"
#include "usb_device_libusb_mac.hpp"
#endif

#include "usb_device_vcp.hpp"
#include "usb_device_iokit.hpp"

#include "usb_device_list.hpp"


#define ANT_SI_BSD_NAME "ANTUSBStick.slabvcp"


BOOL SiDeviceMatch(const USBDeviceSI*const & pclDevice_)
{
   BOOL bReturnValue;

   CFStringRef hDevicePath = CFStringCreateWithCString(kCFAllocatorDefault, (const char*)(pclDevice_->GetBsdName()), kCFStringEncodingUTF8);
   if(CFStringFindWithOptions(hDevicePath, CFSTR(ANT_SI_BSD_NAME), CFRangeMake(0,CFStringGetLength(hDevicePath)), 0, NULL) == FALSE)
      bReturnValue = FALSE;
   else
      bReturnValue = TRUE;

   CFRelease(hDevicePath);
   return bReturnValue;
}

namespace
{
   BOOL IOKitDeviceMatch(const USBDeviceIOKit*const & pclDevice_)
   {
      //const USHORT ANT_USB_VID = 0x0FCF;
      #if defined(LIBUSB_DRIVER)
      return ((pclDevice_->GetVid() == USBDeviceHandle::USB_ANT_VID) && (pclDevice_->GetPid() == USB_ANT_DEV_BOARD_PID));
      #else
      return (pclDevice_->GetVid() == USBDeviceHandle::USB_ANT_VID);
      #endif

   }
}
#if defined(LIBUSB_DRIVER)
BOOL LibusbDeviceMatch(const USBDeviceLibusb* const & pclDevice_)
{
   //!!Can also find device by it's description string?
   USHORT usVid = pclDevice_->GetVid();
   return (usVid == USBDeviceHandle::USB_ANT_VID || usVid == USBDeviceHandle::USB_ANT_VID_TWO);
}
#endif


BOOL USBDeviceHandle::CopyANTDevice(const USBDevice*& pclUSBDeviceCopy_, const USBDevice* pclUSBDeviceOrg_)
{
   if (pclUSBDeviceOrg_ == NULL)
      return FALSE;

   if (pclUSBDeviceCopy_ != NULL)
      return FALSE;


   switch(pclUSBDeviceOrg_->GetDeviceType())
   {
      case DeviceType::SI_LABS:
      {
         const USBDeviceSI& clDeviceSi = dynamic_cast<const USBDeviceSI&>(*pclUSBDeviceOrg_);
         pclUSBDeviceCopy_ = new USBDeviceSI(clDeviceSi);
         break;
      }

      case DeviceType::SI_LABS_IOKIT:
      {
         const USBDeviceIOKit& clDeviceSiIOKit = dynamic_cast<const USBDeviceIOKit&>(*pclUSBDeviceOrg_);
         pclUSBDeviceCopy_ = new USBDeviceIOKit(clDeviceSiIOKit);
         break;
      }

      case DeviceType::IO_KIT:
      {
         const USBDeviceIOKit& clDeviceIOKit = dynamic_cast<const USBDeviceIOKit&>(*pclUSBDeviceOrg_);
         pclUSBDeviceCopy_ = new USBDeviceIOKit(clDeviceIOKit);
         break;
      }

      #if defined(LIBUSB_DRIVER)
      case DeviceType::LIBUSB:
      {
         const USBDeviceLibusb& clDeviceLibusb = dynamic_cast<const USBDeviceLibusb&>(*pclUSBDeviceOrg_);
         pclUSBDeviceCopy_ = new USBDeviceLibusb(clDeviceLibusb);
         break;
      }
      #endif

      default:
      {
         return FALSE;
      }
   }

   return TRUE;
}


//!!Just here temporarily until we get ANTDeviceList to do it.
const ANTDeviceList USBDeviceHandle::GetAllDevices(ULONG ulDeviceTypeField_)
{
   ANTDeviceList clDeviceList;

   if( (ulDeviceTypeField_ & DeviceType::SI_LABS) != 0)
   {
      const USBDeviceListSI clDeviceSIList = USBDeviceHandleSI::GetAllDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceSIList.GetSubList(SiDeviceMatch) );
   }

   if( (ulDeviceTypeField_ & DeviceType::SI_LABS_IOKIT) != 0)
   {
      const USBDeviceListIOKit clDeviceSIIOKitList = USBDeviceHandleSIIOKit::GetAllDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceSIIOKitList.GetSubList(IOKitDeviceMatch) );
   }

   if( (ulDeviceTypeField_ & DeviceType::IO_KIT) != 0)
   {
      const USBDeviceListIOKit clDeviceIOKitList = USBDeviceHandleIOKit::GetAllDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceIOKitList.GetSubList(IOKitDeviceMatch) );
   }

   #if defined(LIBUSB_DRIVER)
   if( (ulDeviceTypeField_ & DeviceType::LIBUSB) != 0)
   {
      const USBDeviceListLibusb clDeviceLibusbList = USBDeviceHandleLibusb::GetAllDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceLibusbList.GetSubList(LibusbDeviceMatch) );
   }
   #endif

/* Output for debugging
   UCHAR aucProductDescription[256];

   printf("*********************************************\n");
   for(int i=0; i<clDeviceList.GetSize(); i++)
   {
      if(clDeviceList[i]->GetProductDescription(aucProductDescription, sizeof(aucProductDescription)))
         printf("Product: %s\n", (char*) aucProductDescription);
   }
   printf("*********************************************\n");
*/

/*
   printf("************************************************************\n");

   ULONG ulSize = clDeviceList.GetSize();
   UCHAR aucProductDescription[256];

   for(ULONG i=0; i<ulSize; i++)
   {
      if(clDeviceList[i]->GetProductDescription(aucProductDescription, sizeof(aucProductDescription)))
         printf("Product: %s\n", (char*) aucProductDescription);
      printf("Vid: %u\n", clDeviceList[i]->GetVid());
      printf("Pid: %u\n", clDeviceList[i]->GetPid());
      printf("Serial Number: %u\n", clDeviceList[i]->GetSerialNumber());
      printf("\n");
   }

   printf("************************************************************\n");
*/

   return clDeviceList;
}

//!!Just here temporarily until we get ANTDeviceList to do it.
const ANTDeviceList USBDeviceHandle::GetAvailableDevices(ULONG ulDeviceTypeField_)
{
   ANTDeviceList clDeviceList;

   if( (ulDeviceTypeField_ & DeviceType::SI_LABS) != 0)
   {
      const USBDeviceListSI clDeviceSIList = USBDeviceHandleSI::GetAvailableDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceSIList.GetSubList(SiDeviceMatch) );
   }

   if( (ulDeviceTypeField_ & DeviceType::SI_LABS_IOKIT) != 0)
   {
      const USBDeviceListIOKit clDeviceSIIOKitList = USBDeviceHandleSIIOKit::GetAvailableDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceSIIOKitList.GetSubList(IOKitDeviceMatch) );
   }

   if( (ulDeviceTypeField_ & DeviceType::IO_KIT) != 0)
   {
      const USBDeviceListIOKit clDeviceIOKitList = USBDeviceHandleIOKit::GetAvailableDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceIOKitList.GetSubList(IOKitDeviceMatch) );
   }

   #if defined(LIBUSB_DRIVER)
   if( (ulDeviceTypeField_ & DeviceType::LIBUSB) != 0)
   {
      const USBDeviceListLibusb clDeviceLibusbList = USBDeviceHandleLibusb::GetAvailableDevices();  //!!There is a list copy here!
      clDeviceList.Add(clDeviceLibusbList.GetSubList(LibusbDeviceMatch) );
   }
   #endif

   return clDeviceList;
}


//!!Polymorphism would be easier to implement!
BOOL USBDeviceHandle::Open(const USBDevice& clDevice_, USBDeviceHandle*& pclDeviceHandle_, ULONG ulBaudRate_)
{
   //dynamic_cast does not handle *& types

   BOOL bSuccess;
   switch(clDevice_.GetDeviceType())
   {
      case DeviceType::SI_LABS:
      {
         const USBDeviceSI& clDeviceSi = dynamic_cast<const USBDeviceSI&>(clDevice_);

         USBDeviceHandleSI* pclDeviceHandleSi;
         bSuccess = USBDeviceHandleSI::Open(clDeviceSi, pclDeviceHandleSi, ulBaudRate_);

         //pclDeviceHandle_ = dynamic_cast<USBDeviceHandle*>(pclDeviceHandleSi);
         pclDeviceHandle_ = pclDeviceHandleSi;
         break;
      }

      case DeviceType::SI_LABS_IOKIT:
      {
         const USBDeviceIOKit& clDeviceSi = dynamic_cast<const USBDeviceIOKit&>(clDevice_);

         USBDeviceHandleSIIOKit* pclDeviceHandleSiIOKit;
         bSuccess = USBDeviceHandleSIIOKit::Open(clDeviceSi, pclDeviceHandleSiIOKit, ulBaudRate_);

         //pclDeviceHandle_ = dynamic_cast<USBDeviceHandle*>(pclDeviceHandleSiIOKit);
         pclDeviceHandle_ = pclDeviceHandleSiIOKit;
         break;
      }

      case DeviceType::IO_KIT:
      {
         const USBDeviceIOKit& clDeviceIOKit = dynamic_cast<const USBDeviceIOKit&>(clDevice_);

         USBDeviceHandleIOKit* pclDeviceHandleIOKit;
         bSuccess = USBDeviceHandleIOKit::Open(clDeviceIOKit, pclDeviceHandleIOKit);

         //pclDeviceHandle_ = dynamic_cast<USBDeviceHandle*>(pclDeviceHandleIOKit);
         pclDeviceHandle_ = pclDeviceHandleIOKit;
         break;
      }

      #if defined(LIBUSB_DRIVER)
      case DeviceType::LIBUSB:
      {
         const USBDeviceLibusb& clDeviceLibusb = dynamic_cast<const USBDeviceLibusb&>(clDevice_);

         USBDeviceHandleLibusb* pclDeviceHandleLibusb;
         bSuccess = USBDeviceHandleLibusb::Open(clDeviceLibusb, pclDeviceHandleLibusb);

         //pclDeviceHandle_ = dynamic_cast<USBDeviceHandle*>(pclDeviceHandleLibusb);
         pclDeviceHandle_ = pclDeviceHandleLibusb;
         break;
      }
      #endif

      default:
      {
         pclDeviceHandle_ = NULL;
         bSuccess = FALSE;
         break;
      }
   }

   return bSuccess;
}

BOOL USBDeviceHandle::Close(USBDeviceHandle*& pclDeviceHandle_, BOOL bReset_)
{
   if(pclDeviceHandle_ == NULL)
      return FALSE;

   //dynamic_cast does not handle *& types

   BOOL bSuccess;
   switch(pclDeviceHandle_->GetDevice().GetDeviceType())
   {
      case DeviceType::SI_LABS:
      {
         USBDeviceHandleSI* pclDeviceHandleSi = reinterpret_cast<USBDeviceHandleSI*>(pclDeviceHandle_);
         bSuccess = USBDeviceHandleSI::Close(pclDeviceHandleSi, bReset_);

         pclDeviceHandle_ = pclDeviceHandleSi;
         break;
      }

      case DeviceType::SI_LABS_IOKIT:
      {
         USBDeviceHandleSIIOKit* pclDeviceHandleSiIOKit = reinterpret_cast<USBDeviceHandleSIIOKit*>(pclDeviceHandle_);
         bSuccess = USBDeviceHandleSIIOKit::Close(pclDeviceHandleSiIOKit, bReset_);

         pclDeviceHandle_ = pclDeviceHandleSiIOKit;
         break;
      }

      case DeviceType::IO_KIT:
      {
         USBDeviceHandleIOKit* pclDeviceHandleIOKit = reinterpret_cast<USBDeviceHandleIOKit*>(pclDeviceHandle_);
         bSuccess = USBDeviceHandleIOKit::Close(pclDeviceHandleIOKit, bReset_);

         pclDeviceHandle_ = pclDeviceHandleIOKit;
         break;
      }

     #if defined(LIBUSB_DRIVER)
     case DeviceType::LIBUSB:
     {
         USBDeviceHandleLibusb* pclDeviceHandleLibusb = reinterpret_cast<USBDeviceHandleLibusb*>(pclDeviceHandle_);
         bSuccess = USBDeviceHandleLibusb::Close(pclDeviceHandleLibusb, bReset_);

         pclDeviceHandle_ = pclDeviceHandleLibusb;
         break;
     }
     #endif

      default:
      {
         pclDeviceHandle_ = NULL;
         bSuccess = FALSE;
         break;
      }
   }

   return bSuccess;
}


#endif //defined(DSI_TYPES_MACINTOSH)
