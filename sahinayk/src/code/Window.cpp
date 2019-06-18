#include "Window.hpp"
//=========================================================================
CWindow::CWindow () {
	m_window = NULL;
	m_screenSurface = NULL;
	m_renderer = NULL;
}
//=========================================================================
CWindow::~CWindow () {
	if (m_window) SDL_DestroyWindow ( m_window );
}
//=========================================================================
bool CWindow::InitializeWindow (const char * title,
				const int & xpos,
				const int & ypos,
				const int & width,
				const int & height,
				const int & fullscreen) 
{
	m_window = SDL_CreateWindow ( title, xpos, ypos, width, height, fullscreen );
	if ( m_window ) {
		printf ( "Window is created!\n" );
		return true;
	}
	else {
		printf ( "Window could not be created!\n" );
		return false;
	}
}
//=========================================================================
bool CWindow::CreateRenderer (	const int & num,
		      		const int & renderopt)
{
	m_renderer = SDL_CreateRenderer (m_window, num, renderopt);
	if ( m_renderer ) {
		printf("Renderer is created!\n");
		SDL_SetRenderDrawColor (m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		return true;
	}
	else {
		printf("Renderer could not be created!\n");
		return false;
	}
}
//=========================================================================
bool CWindow::LoadImage (void) {
	
}
//=========================================================================
//=========================================================================
//=========================================================================
void CWindow::DestroyRenderer ( void ) {
	if ( m_renderer ) SDL_DestroyRenderer ( m_renderer );
}
//=========================================================================
void CWindow::DestroyWindow (void) {
	if ( m_window ) SDL_DestroyWindow ( m_window );
}
//=========================================================================
SDL_Window* CWindow::GetWindow ( void ) {
	return m_window;
}
//=========================================================================
SDL_Renderer * CWindow::GetRenderer ( void ) {
	return m_renderer;
}
