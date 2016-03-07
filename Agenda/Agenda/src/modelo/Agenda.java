package modelo;


import java.util.List;

import persistencia.dao.PersonaDAO;
import dto.PersonaDTO;


public class Agenda 
{
	private PersonaDAO persona;	
	
	public Agenda()
	{
		persona = new PersonaDAO();
	}
	
	public void agregarPersona(PersonaDTO nuevaPersona)
	{
		persona.insert(nuevaPersona);
	}

	public void borrarPersona(PersonaDTO persona_a_eliminar) 
	{
		persona.delete(persona_a_eliminar);
	}
	
	public List<PersonaDTO> obtenerPersonas()
	{
		return persona.readAll();		
	}
	
}
