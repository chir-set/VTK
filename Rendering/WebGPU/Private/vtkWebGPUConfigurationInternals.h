// SPDX-FileCopyrightText: Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
// SPDX-License-Identifier: BSD-3-Clause

#ifndef vtkWebGPUConfigurationInternals_h
#define vtkWebGPUConfigurationInternals_h

#include "vtkWebGPUConfiguration.h"
#include "vtk_wgpu.h"

VTK_ABI_NAMESPACE_BEGIN
class vtkWebGPUConfigurationInternals
{
public:
  wgpu::Adapter Adapter;
  wgpu::Device Device;
  bool DeviceReady = false;

  // in milliseconds
  static double DefaultTimeout;
  // We only keep one webgpu Instance around.
  static wgpu::Instance Instance;
  // Helps clean up the instance after it is no longer needed.
  static std::size_t InstanceCount;

  static void AddInstanceRef();

  static void ReleaseInstanceRef();

  static wgpu::BackendType ToWGPUBackendType(vtkWebGPUConfiguration::BackendType backend);

  static vtkWebGPUConfiguration::BackendType FromWGPUBackendType(wgpu::BackendType backend);

  static wgpu::PowerPreference ToWGPUPowerPreferenceType(
    vtkWebGPUConfiguration::PowerPreferenceType powerPreference);

  static void OnAdapterRequestCompleted(
    WGPURequestAdapterStatus status, WGPUAdapter cAdapter, const char* message, void* userdata);

  static void OnDeviceRequestCompleted(
    WGPURequestDeviceStatus status, WGPUDevice cDevice, const char* message, void* userdata);
};
VTK_ABI_NAMESPACE_END

#endif
// VTK-HeaderTest-Exclude: vtkWebGPUConfigurationInternals.h
