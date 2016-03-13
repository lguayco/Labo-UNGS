package presentacion.reportes;

import java.util.List;
import java.util.Map;


import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import net.sf.jasperreports.engine.JasperReport;
import net.sf.jasperreports.engine.data.JRBeanCollectionDataSource;
import net.sf.jasperreports.engine.util.JRLoader;
import net.sf.jasperreports.view.JasperViewer;
import dto.PersonaDTO;

public class ReporteAgenda
{
	private JasperReport reporte;
	private JasperViewer reporteViewer;
	private JasperPrint	reporteLleno;
	private Map parametersMap;
 
	//Recibe la lista de personas y un mapa con los parámetros que serán enviados 
	//al reporte.
	public ReporteAgenda(List<PersonaDTO> personas,Map<String,Object> params)
    {
    	try 
		{
    		this.parametersMap=params;
			this.reporte = (JasperReport) JRLoader.loadObjectFromFile( "reportes\\ReporteAgenda.jasper" );
			this.reporteLleno = JasperFillManager.fillReport(this.reporte, parametersMap, new JRBeanCollectionDataSource(personas));
		}
		catch( JRException ex ) 
		{
			ex.printStackTrace();
		}
    }       
    
    public void mostrar()
	{
  	
		this.reporteViewer = new JasperViewer(this.reporteLleno,false);
		this.reporteViewer.setVisible(true);
	}
   
}	