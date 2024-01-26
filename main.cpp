#include <vtkActor.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkCubeSource.h>
#include <vtkProperty.h>

int main(int, char* [])
{
    vtkNew<vtkCubeSource> cube1;
    vtkNew<vtkPolyDataMapper> mapper1;
    vtkNew<vtkActor> actor1;
    mapper1->SetInputConnection(cube1->GetOutputPort());
    actor1->SetMapper(mapper1);
    actor1->SetPosition(0, 0, 0);
    actor1->GetProperty()->SetOpacity(1);

    vtkNew<vtkCubeSource> cube2;
    vtkNew<vtkPolyDataMapper> mapper2;
    vtkNew<vtkActor> actor2;
    mapper2->SetInputConnection(cube2->GetOutputPort());
    actor2->SetMapper(mapper2);
    actor2->SetPosition(5, 0, 0);
    actor2->GetProperty()->SetOpacity(0.5);

    vtkNew<vtkRenderer> renderer;
    renderer->AddActor(actor1);
    renderer->AddActor(actor2);

    vtkNew<vtkRenderWindow> renderWindow;
    renderWindow->AddRenderer(renderer);

    vtkNew<vtkRenderWindowInteractor> renderWindowInteractor;
    renderWindowInteractor->SetRenderWindow(renderWindow);

    renderWindow->Render();
    renderWindowInteractor->Start();
}