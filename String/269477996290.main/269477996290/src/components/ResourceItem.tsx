import { Link } from 'react-router-dom';
import { Resource } from '@/types';

interface ResourceItemProps {
  resource: Resource;
  onEdit?: (id: string) => void;
  onDelete?: (id: string) => void;
}

export function ResourceItem({ resource, onEdit, onDelete }: ResourceItemProps) {
  return (
     <div className="group bg-white dark:bg-gray-800 rounded-lg shadow-sm border border-gray-100 dark:border-gray-700 overflow-hidden transition-all duration-300 hover:shadow-md hover:-translate-y-1">
       <Link to={`/resource/${resource.id}`} className="block p-4">
         <div className="flex justify-between items-start mb-2">
           <h3 className="text-base font-medium text-gray-900 dark:text-white group-hover:text-primary dark:group-hover:text-primary transition-colors duration-300">
             {resource.title}
           </h3>
           
           <div className="flex space-x-1 opacity-0 group-hover:opacity-100 transition-all duration-300 transform translate-y-1 group-hover:translate-y-0">
             {onEdit && (
               <button
                 onClick={(e) => {
                   e.preventDefault();
                   e.stopPropagation();
                   onEdit(resource.id);
                 }}
                 className="p-1.5 text-gray-500 hover:text-primary transition-all duration-300 hover:bg-primary/10 rounded-full hover:shadow-sm"
                 aria-label="编辑资源"
               >
                 <i class="fa-solid fa-pencil"></i>
               </button>
             )}
             
             {onDelete && (
               <button
                 onClick={(e) => {
                   e.preventDefault();
                   e.stopPropagation();
                   if (confirm(`确定要删除资源"${resource.title}"吗？`)) {
                     onDelete(resource.id);
                   }
                 }}
                 className="p-1.5 text-gray-500 hover:text-error transition-all duration-300 hover:bg-error/10 rounded-full hover:shadow-sm"
                 aria-label="删除资源"
               >
                 <i class="fa-solid fa-trash"></i>
               </button>
             )}
           </div>
         </div>
         
         <div className="flex flex-wrap items-center gap-2 mt-3 text-xs text-gray-500 dark:text-gray-400">
           <span className="flex items-center bg-gray-100 dark:bg-gray-700 px-2 py-0.5 rounded-full">
             <i class="fa-solid fa-user mr-1"></i>{resource.author}
           </span>
           <span className="flex items-center bg-gray-100 dark:bg-gray-700 px-2 py-0.5 rounded-full">
             <i class="fa-solid fa-calendar mr-1"></i>
             {new Date(resource.createdAt).toLocaleString()}
           </span>
            {resource.tags && resource.tags.slice(0, 2).map((tag, i) => (
              <span key={i} className="flex items-center bg-tertiary/10 text-tertiary px-2 py-0.5 rounded-full transition-colors duration-300 group-hover:bg-tertiary/20">
                <i class="fa-solid fa-tag mr-1"></i>{tag}
              </span>
            ))}
         </div>
       </Link>
     </div>
  );
}