using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GUI
{
    class NoConvexCutterException : Exception
    {
        public NoConvexCutterException(string message = "Non-convex cutter defined!") : base(message)
        { }
    }
}
