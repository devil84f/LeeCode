import { createContext, useContext, useState, useEffect, ReactNode } from 'react';
import { Resource, ResourceType } from '@/types';
import { getResourceTypes, addResourceType, deleteResourceType } from '@/mocks/types';
import { getResources, getResourceById, addResource, updateResource, deleteResource, getResourcesByTypeId } from '@/mocks/resources';

// 定义上下文类型
interface ResourceContextType {
  resourceTypes: ResourceType[];
  resources: Resource[];
  getResourceById: (id: string) => Resource | undefined;
  getResourcesByTypeId: (typeId: string) => Resource[];
  addResourceType: (type: Omit<ResourceType, 'id' | 'createdAt'>) => ResourceType;
  deleteResourceType: (id: string) => void;
  addResource: (resource: Omit<Resource, 'id' | 'createdAt' | 'updatedAt'>) => Resource;
  updateResource: (id: string, updatedData: Partial<Resource>) => Resource | null;
  deleteResource: (id: string) => void;
}

// 创建上下文
const ResourceContext = createContext<ResourceContextType | undefined>(undefined);

// 上下文提供者组件
export function ResourceProvider({ children }: { children: ReactNode }) {
  const [resourceTypes, setResourceTypes] = useState<ResourceType[]>([]);
  const [resources, setResources] = useState<Resource[]>([]);

  // 加载资源类型和资源数据
  useEffect(() => {
    const loadData = () => {
      const types = getResourceTypes();
      const res = getResources();
      setResourceTypes(types);
      setResources(res);
    };

    loadData();
    
    // 监听localStorage变化，以便在其他组件修改数据后更新
    const handleStorageChange = (e: StorageEvent) => {
      if (e.key === 'resourceTypes' || e.key === 'resources' || e.key === null) {
        loadData();
      }
    };

    window.addEventListener('storage', handleStorageChange);
    return () => window.removeEventListener('storage', handleStorageChange);
  }, []);

  // 实现上下文方法
  const contextValue: ResourceContextType = {
    resourceTypes,
    resources,
    getResourceById,
    getResourcesByTypeId,
    addResourceType: (type) => {
      const newType = addResourceType(type);
      setResourceTypes(getResourceTypes());
      return newType;
    },
     deleteResourceType: (id) => {
       // 先删除该类型下的所有资源
       const resourcesOfType = getResourcesByTypeId(id);
       resourcesOfType.forEach(resource => deleteResource(resource.id));
       
       // 再删除类型
       deleteResourceType(id);
       
       // 刷新状态
       setResources(getResources());
       setResourceTypes(getResourceTypes());
       
       // 触发storage事件，通知其他组件数据已更新
       window.dispatchEvent(new Event('storage'));
     },
    addResource: (resource) => {
      const newResource = addResource(resource);
      setResources(getResources());
      return newResource;
    },
    updateResource: (id, updatedData) => {
      const updatedResource = updateResource(id, updatedData);
      setResources(getResources());
      return updatedResource;
    },
    deleteResource: (id) => {
      deleteResource(id);
      setResources(getResources());
    }
  };

  return (
    <ResourceContext.Provider value={contextValue}>
      {children}
    </ResourceContext.Provider>
  );
}

// 自定义hook，方便组件使用上下文
export function useResourceContext() {
  const context = useContext(ResourceContext);
  if (context === undefined) {
    throw new Error('useResourceContext must be used within a ResourceProvider');
  }
  return context;
}