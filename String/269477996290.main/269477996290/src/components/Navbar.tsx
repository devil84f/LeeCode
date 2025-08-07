import { Link } from 'react-router-dom';

export function Navbar() {
  return (
      <nav className="bg-white dark:bg-gray-900 border-b border-gray-200 dark:border-gray-700 shadow-sm transition-all duration-300 bg-gradient-to-r from-primary/5 to-tertiary/5 dark:from-primary/5 dark:to-tertiary/5">
       <div className="max-w-7xl mx-auto px-4 sm:px-6 lg:px-8">
         <div className="flex justify-between h-16">
           <div className="flex items-center">
           <Link to="/" className="flex-shrink-0 flex items-center group">
                 <img 
                   src="https://lf-code-agent.coze.cn/obj/x-ai-cn/269477996290/attachment/微信图片_20250807152948_20250807153001.jpg" 
                   alt="系统优化与调度团队LOGO" 
                   className="h-10 w-auto mr-3 rounded transition-transform duration-300 group-hover:scale-105"
                 />
                 <i class="fa-solid fa-home mr-2 text-primary transition-colors duration-300"></i>
                 <span className="text-xl font-bold text-primary dark:text-primary transition-colors duration-300 group-hover:text-primary-dark dark:group-hover:text-primary-light">
                   系统优化与调度SUST_SOS
                 </span>
               </Link>
           </div>
           
           <div className="flex items-center space-x-4">
             <Link 
               to="/types/manage" 
               className="px-3 py-2 rounded-md text-sm font-medium text-gray-700 dark:text-gray-300 hover:bg-gray-100 dark:hover:bg-gray-800 transition-all duration-300 hover:shadow-sm"
             >
               <i class="fa-solid fa-cog mr-1 transition-transform duration-300 hover:rotate-12"></i>分类管理
             </Link>
             
                <Link 
                  to="/resource/upload" 
                  className="px-4 py-2 rounded-md text-sm font-medium bg-blue-600 text-white hover:bg-blue-700 transition-all duration-300 transform hover:scale-105 hover:shadow-md inline-flex items-center justify-center whitespace-nowrap"
                >
                  <i class="fa-solid fa-cloud-upload-alt mr-2"></i>
                  <span>上传资源</span>
                </Link>
           </div>
         </div>
       </div>
     </nav>
   )
}