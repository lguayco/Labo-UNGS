#include <windows.h>
#include "Window.h";
#include "Device.h";
#include "Camera.h";
#include "BillBoard.h";
#include "Scene.h";
#include "Mesh.h";
using namespace DirectX;
//--------------------------------------------------------------------------------------
// Forward declarations
//--------------------------------------------------------------------------------------
void CleanupDevice();
void InitScene();


//--------------------------------------------------------------------------------------
// Entry point to the program. Initializes everything and goes into a message processing 
// loop. Idle time is used to render the scene.
//--------------------------------------------------------------------------------------
int WINAPI InitScene(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER( hPrevInstance );
    UNREFERENCED_PARAMETER( lpCmdLine );

	// crear ventana
	Window* my_window = new Window( hInstance, nCmdShow);

	// crear device
	Device* my_device = new Device(my_window);

	// crear escena
	Scene* my_scene = new Scene();
	
	// crear camara
	Camera* camera = new Camera();
	camera->position = XMFLOAT3( 0.0f, 3.0f, -6.0f);
	camera->at_point = XMFLOAT3( 0.0f, 1.0f, 0.0f);
	camera->up_dir = XMFLOAT3( 0.0f, 1.0f, 0.0f);
	camera->ancho = 800;
	camera->alto = 600;
	camera->angulo_de_vision_y = 3.14 / 4.0;

	// agregar camara a escena
	my_scene->la_camara = camera;

	// crear n billboard
	BillBoard* billboard = new BillBoard();
	billboard->textura =  my_device->LoadTexture(L"seafloor.dds");

	// agregar billboard a la escena
	my_scene->el_billboard = billboard;

	//Agrego el mesh?
	//Mesh* my_mesh = new Mesh();

	// ventana->mostrarEscena(escena); ?
	//my_window->mostrarEscena(my_scene)

    // Main message loop
    MSG msg = {0};
    while( WM_QUIT != msg.message )
    {
        if( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) )
        {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }
        else
        {
            my_device->Render(my_scene);
        }
    }
    return ( int )msg.wParam;
}
