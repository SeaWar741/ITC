using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;

// For more information on enabling MVC for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace TallerDeServicios.Controllers
{
    [ApiController]
    [Route("api/[controller]")]

    public class HolaMundoController : ControllerBase
    {
        [HttpGet]
        public ActionResult<IEnumerable<string>> Get()
        {
            return new string[] {"Hola Mundo 😁 desde Juan Carlos API"};
        }
    }
}
