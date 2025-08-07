import { Link } from 'react-router-dom';
import { ResourceType } from '@/types';
import { getResourcesByTypeId } from '@/mocks/resources';

interface ResourceTypeCardProps {
  type: ResourceType;
  onDelete?: (id: string) => void;
}

export function ResourceTypeCard({ type, onDelete }: ResourceTypeCardProps) {
  const resourcesCount = getResourcesByTypeId(type.id).length;
  
  // 默认图标
  const defaultIcon = "https://space.coze.cn/api/coze_space/gen_image?image_size=square&prompt=default%20resource%2C%20folder%2C%20category%20icon&sign=bea42825413aa52a3e6e63740c446277";
  
  return (
      <div className="group relative bg-white dark:bg-gray-800 rounded-xl shadow-md overflow-hidden transition-all duration-300 hover:shadow-lg border border-gray-100 dark:border-gray-700 hover:-translate-y-1 flex flex-col h-full">
       <Link to={`/resources/${type.id}`} className="block p-6 h-full">
         <div className="flex items-start justify-between mb-4">
           <h3 className="text-lg font-semibold text-gray-900 dark:text-white group-hover:text-primary dark:group-hover:text-primary transition-colors duration-300">
             {type.name}
           </h3>
           
           <div className="flex items-center">
             {type.iconUrl ? (
               <img 
                 src={type.iconUrl} 
                 alt={`${type.name} icon`} 
                 className="w-8 h-8 object-contain rounded-md shadow-sm border border-gray-100 dark:border-gray-600 transition-transform duration-300 group-hover:scale-110"
               />
             ) : (
               <div className="w-8 h-8 flex items-center justify-center bg-gray-100 dark:bg-gray-700 rounded-md shadow-sm">
                 <i class="fa-solid fa-folder text-gray-500 dark:text-gray-400"></i>
               </div>
             )}
             
             {onDelete && (
               <button
                 onClick={(e) => {
                   e.preventDefault();
                   e.stopPropagation();
                   if (confirm(`确定要删除分类"${type.name}"吗？这将同时删除该分类下的所有资源。`)) {
                     onDelete(type.id);
                   }
                 }}
                 className="ml-2 text-gray-400 hover:text-error transition-all duration-300 z-10 relative hover:scale-110"
                 aria-label="删除分类"
               >
                 <i class="fa-solid fa-trash"></i>
               </button>
             )}
           </div>
         </div>
         
          <p className="text-sm text-gray-600 dark:text-gray-300 mb-6 line-clamp-2 transition-all duration-300 group-hover:text-gray-900 dark:group-hover:text-gray-100">
            {type.description || '暂无描述'}
          </p>
          
          <div className="flex flex-wrap items-center justify-between gap-2 mt-auto pt-4 text-xs">
            <span className="bg-primary/10 text-primary px-2 py-1 rounded-full transition-all duration-300 group-hover:bg-primary/20">
              <i class="fa-solid fa-database mr-1"></i>资源数量: {resourcesCount}
            </span>
            <span className="text-gray-500 dark:text-gray-400">创建于: {new Date(type.createdAt).toLocaleDateString()}</span>
          </div>
       </Link>
       
       <div className="absolute inset-0 bg-gradient-to-t from-primary/10 to-transparent opacity-0 group-hover:opacity-100 transition-opacity duration-500 pointer-events-none"></div>
     </div>
  );
}