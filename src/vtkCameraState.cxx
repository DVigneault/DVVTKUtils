#ifndef vtkCameraState_cxx
#define vtkCameraState_cxx

#include <vtkCameraState.h>
#include <vtkSmartPointer.h>
#include <vtkCamera.h>

namespace vtk
{

void
CameraState
::CaptureState(vtkCamera* const camera)
{
  camera->GetPosition(   this->Position );
  camera->GetFocalPoint( this->FocalPoint );
  camera->GetViewUp(     this->ViewUp );
  this->ViewAngle =          camera->GetViewAngle();
  this->ParallelScale =      camera->GetParallelScale();
  this->ParallelProjection = camera->GetParallelProjection();
}
  
void
CameraState
::RestoreState(vtkCamera* const camera) const
{
  camera->SetPosition(          this->Position);
  camera->SetFocalPoint(        this->FocalPoint);
  camera->SetViewUp(            this->ViewUp);
  camera->SetViewAngle(         this->ViewAngle);
  camera->SetParallelScale(     this->ParallelScale);
  camera->SetParallelProjection(this->ParallelProjection);
}

} // end namespace vtk

#endif
