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

    public class OperacionesController : ControllerBase
    {
        [HttpGet("{op}/{num1}/{num2}")]
        public IActionResult Get(string op, int num1, int num2)
        {
            switch (op)
            {
                case "suma":
                    return Ok(new Operaciones { Valor1 = num1, Valor2 = num2, Resultado = num1 + num2 });
                case "resta":
                    return Ok(new Operaciones { Valor1 = num1, Valor2 = num2, Resultado = num1 - num2 });
                case "mult":
                    return Ok(new Operaciones { Valor1 = num1, Valor2 = num2, Resultado = num1 * num2 });
                case "div":
                    return Ok(new Operaciones { Valor1 = num1, Valor2 = num2, Resultado = num1 / num2 });
                default:
                    return Ok(new Operaciones { Valor1 = num1, Valor2 = num2 });

            }
        }

        [HttpGet("{operacion}")]
        public ActionResult<IEnumerable<string>> Get(string operacion)
        {
            switch (operacion)
            {
                case "suma":
                    return new string[] { "Utiliza los siguientes parámetros: operacion , numero1, numero2. El orden de operación es numero1+numero2." };
                case "resta":
                    return new string[] { "Utiliza los siguientes parámetros: operacion , numero1, numero2. El orden de operación es numero1-numero2." };
                case "mult":
                    return new string[] { "Utiliza los siguientes parámetros: operacion , numero1, numero2. El orden de operación es numero1*numero2." };
                case "div":
                    return new string[] { "Utiliza los siguientes parámetros: operacion , numero1, numero2. El orden de operación es numero1/numero2." };
                default:
                    return new string[] { "Error, petición incorrecta, revisar sintaxis" };
            }
        }
    }
}

