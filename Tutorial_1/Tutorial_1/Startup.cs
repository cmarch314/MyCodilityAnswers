using Microsoft.Owin;
using Owin;

[assembly: OwinStartupAttribute(typeof(Tutorial_1.Startup))]
namespace Tutorial_1
{
    public partial class Startup {
        public void Configuration(IAppBuilder app) {
            ConfigureAuth(app);
        }
    }
}
